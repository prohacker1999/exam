set ns [new Simulator]

set namfile [open s3.nam w]
$ns namtrace-all $namfile
set tracefile [open s3.tr w]
$ns trace-all $tracefile

proc finish {} {
	global ns namfile tracefile
	$ns flush-trace
	close $namfile
	close $tracefile

	exec nam s3.nam &	
	exec awk-f s3.awk s3.tr > s3graph &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]


$n0 label "TCPSource"
$n6 label "TCPSink"

$ns color 1 red

$n0 color blue
$n6 color orange

$ns duplex-link $n0 $n1 3Mb 20ms DropTail
$ns make-lan "$n1 $n2 $n3 $n4 $n5 $n6" 2Mb 40ms LL Queue/DropTail Mac/802_3

$ns duplex-link-op $n0 $n1 orient right

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp

$tcp set class_ 1

set tcpsink [new Agent/TCPSink]
$ns attach-agent $n6 $tcpsink

set ftp [new Application/FTP]
$ftp attach-agent $tcp

$ns connect $tcp $tcpsink

$ns at 1.0 "$ftp start"
$ns at 5.0 "$ftp stop"
$ns at 5.5 "finish"
$ns run
