all:clean
	iverilog -o test hyCnt.v hyCntTb.v
	vvp -n test -lxt2
	cp hyCntTb.vcd test.lxt
	gtkwave test.lxt

clean: 
	rm -rvf test.lxt hyCntTb.vcd test


