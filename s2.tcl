set ns [new Simulator]

set namfile [open s2.nam w]
$ns namtrace-all $namfile
set tracefile [open s2.tr w]
$ns trace-all $tracefile

proc finish {} {
	global ns namfile tracefile
	$ns flush-trace
	close $namfile
	close $tracefile

	exec nam s2.nam &	
	exec awk-f s2.awk s2.tr &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$n0 label "TCP"
$n1 label "UDP"
$n3 label "NULL-TCPSINK"

$ns color 1 red
$ns color 2 blue

$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 2.75Mb 20ms DropTail

$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp

set tcpsink [new Agent/TCPSink]
$ns attach-agent $n3 $tcpsink

set ftp [new Application/FTP]
$ftp attach-agent $tcp

$ns connect $tcp $tcpsink

set udp [new Agent/UDP]
$ns attach-agent $n1 $udp

set null [new Agent/Null]
$ns attach-agent $n3 $null

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp

$cbr set paketSize_ 500
$cbr set interval_ 0.005

$ns connect $udp $null

$tcp set class_ 1
$udp set class_ 2

$ns at 0.2 "$cbr start"
$ns at 0.1 "$ftp start"
$ns at 4.5 "$cbr stop"
$ns at 4.4 "$ftp stop"
$ns at 5.0 "finish"
$ns run
