#! /usr/bin/perl -w

use Data::Dumper;
use strict;

sub genname {
    if ($_[0] =~ /^(?i:[\da-z])+$/) {
	return $_[0];
    }
    else {
	return $_[1];
    }
}

my (%words, $state, $finish, @table);

while (my $line = <STDIN>) {
    next if $line =~ /(?:^\s*(?:\#)|^\s*$)/;
    chomp $line;
    $line =~ /^\s*([^\s]*)\s+([^\s]*)\s*$/;
    $words{$1}{'token'} = $2;
    $words{$1}{'str'} = $1;
    $words{$1}{'laststate'} = 0;
    print "\"$1\" \"$2\"\n";
}

$state = 0;
$finish = 0;
while (! $finish) {
    $finish = 1;
    for my $word (sort keys %words) {
	my $rest = \$words{$word}{'str'};
	my $laststate = \$words{$word}{'laststate'};
	if ($$rest) {
	    # urizni prvni znak
	    $$rest =~ s/^(.)(.*)$/$2/;
	    my $char = $1;
	    if (! defined($table[$$laststate]{'row'}[ord $char])) {
		$table[$$laststate]{'row'}[ord $char] = ++$state;
		if (! defined($table[$$laststate]{'prefix'})) {
		    $table[$$laststate]{'prefix'} = "";
		}
		$table[$state]{'prefix'} = $table[$$laststate]{'prefix'}.$char;
		$$laststate = $state;
	    }
	    else {
		$$laststate = $table[$$laststate]{'row'}[ord $char];
	    }
	    
	    if (! $$rest) {
		$table[$$laststate]{'token'} = $words{$word}{'token'};
	    }
	    $finish = 0;
	}
    }
}

# generuj lexan.hxx
{
    my ($fh, $token);
    open($fh, ">lexan.hxx") or die "chyba open()";
    select $fh;
    
    print "#ifndef LEXAN_HXX\n";
    print "#define LEXAN_HXX\n\n";

    print "#include <cstdio>\n\n";

    print "#define GETCHAR() getchar()\n\n";

    print "const short POCETSTAVU = ".($state+1).";\n\n";

    print "enum Token {\n";
    print "TOK_ERROR = -1,\n";
    $token = 256;
    for my $i (0..$state) {
	if (defined($table[$i]{'token'})) {
	    print $table[$i]{'token'}," = ",$token++,",\n";
	}
    }
    print "};\n\n";

    print "extern int lexan (void);\n\n";

    print "#endif // LEXAN_HXX\n";
    close $fh;
}

# generuj lexan.cxx
{
    my ($fh, $token);
    open($fh, ">lexan.cxx") or die "chyba open()";
    select $fh;

    print "#include <lexan.hxx>\n\n";

    print "int lexan (void)\n";
    print "{\n";
    print "short poslednikstav = -1;\n";
    print "Token token = TOK_ERROR;\n";
    print "int ch;\n\n";
    # pro kazdy stav udelej navesti
    for my $i (0..$state) {
	my $statename = genname($table[$i]{'prefix'}, $i);
	print "stav_".$statename.": {\n";
	print "    /* prefix: \"".($table[$i]{'prefix'})."\" */\n";
	# konecny stav
	if (defined($table[$i]{'token'})) {
	    print "    /* konecny stav */\n";
	    print "    token = ".($table[$i]{'token'}).";\n";
	    print "    poslednikstav = ".$i.";\n";
	}
	# ostatni stavy
	print "    ch = GETCHAR();\n";
	print "    switch (ch) {\n";
	for my $char (0..255) {
	    if (defined($table[$i]{'row'}[$char])) {
		print "    case '".((chr $char) eq "'" ? "\\'" : (chr $char))
		    ."': {\n";
		print "       goto stav_"
		    .genname($table[$table[$i]{'row'}[$char]]{'prefix'},
			     $table[$i]{'row'}[$char]).";\n";
		print "    }\n";
	    }
	}
	print "    default: goto lexan_konec;\n";
	print "    }\n";
	print "}\n\n";
    }
    print "lexan_konec:\n";
    print "    ungetc(ch, stdin);\n";
    print "    return token;\n";
    print "}\n\n";

    # tabulka jmen tokenu v koncovych stavech
    # print "static const char * const kstavyjmena[POCETSTAVU] =\n{\n";
#     for my $i (0..$state) {
# 	if (defined($table[$i]{'token'})) {
# 	    print '"'.$table[$i]{'token'}.'"';
# 	}
# 	else {
# 	    print "NULL";
# 	}
# 	print ",\n";
#     }
#     print "};\n\n";

    # tabulka koncovych stavu
    print "static const char kstavy[POCETSTAVU] =\n{\n";
    for my $i (0..$state) {
	if (defined($table[$i]{'token'})) {
	    print "1, ";
	}
	else {
	    print "0, ";
	}
	print "\n" if ($i+1) % 20 == 0;
    }
    print "};\n";

    close $fh;
}

select STDOUT;
