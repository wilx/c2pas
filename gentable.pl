
use Data::Dumper;
use strict;

my (%words, $state, $finish, @table);

while (my $line = <STDIN>) {
    next if $line =~ /(?:^\s*\#|^\s*$)/;
    chomp $line;
    $line =~ /^\s*(.*)\s+(.*)\s*$/;
    $words{$1}{'token'} = $2;
    $words{$1}{'str'} = $1;
    $words{$1}{'laststate'} = 0;
}

$state = 0;
$finish = 0;

while (! $finish) {
    $finish = 1;
    for my $word (sort keys %words) {
	my $rest = \$words{$word}{'str'};
	my $laststate = \$words{$word}{'laststate'};
	if ($$rest) {
	    $$rest =~ s/^(.)(.*)$/$2/;
	    my $char = $1;
	    if (! defined($table[$$laststate]{'row'}[ord $char])) {
		$table[$$laststate]{'row'}[ord $char] = ++$state;
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

    print "#include <stdio.h>\n\n";

    print "const short POCETSTAVU = ".($state+1).";\n\n";

    print "enum Token {\n";
    $token = 256;
    for my $i (0..$state) {
	if (defined($table[$i]{'token'})) {
	    print $table[$i]{'token'}," = ",$token++,",\n";
	}
    }
    print "};\n\n";
    
    print "#endif // LEXAN_HXX\n";
    close $fh;
}

# generuj lexan.cxx
{
    my ($fh, $token);
    open($fh, ">lexan.cxx") or die "chyba open()";
    select $fh;

    print "#include <lexan.hxx>\n\n";

    # tabulka prechodu
    print "static short tprech[POCETSTAVU][256] =\n{\n";
    for my $i (0..$state) {
	for my $char (0..255) {
	    if (! defined($table[$i]{'row'}[$char])) {
		$table[$i]{'row'}[$char] = -1;
	    }
	}
	print "{\n";
	print join ", ", @{$table[$i]{'row'}};
	print "\n},\n";
    }
    print "};\n\n";

    # tabulka jmen tokenu v koncovych stavech
    print "static const char * const kstavyjmena[POCETSTAVU] =\n{\n";
    for my $i (0..$state) {
	if (defined($table[$i]{'token'})) {
	    print '"'.$table[$i]{'token'}.'"';
	}
	else {
	    print "NULL";
	}
	print ",\n";
    }
    print "};\n\n";

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
