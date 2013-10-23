`timescale 1ns/1ps

module hyCntTb;
    parameter C_WIDTH = 32;
    parameter CLK_PERIOD = 10;  
    parameter SIM_PERIOD = CLK_PERIOD * 10000;

    reg clk;
    reg rst_n;
    reg[C_WIDTH:1] cnt_in;

    wire[C_WIDTH:1] cnt_out;
    wire int;


    /* 实例化 */
    hyCnt #(C_WIDTH)inst(
	    .clk(clk),
	    .rst_n(rst_n),
	    .cnt_in(cnt_in),
	    .cnt_out(cnt_out),
	    .int(int)
    );
    
    /* 时钟 */
    initial
    begin  
        clk = 0;  
	forever
	    #(CLK_PERIOD/2) clk = ~clk;  
    end 

    /* 复位 */
    initial
    begin  
        #0 rst_n = 0;  
	#20 rst_n = 1;
    end

    /* 赋值 */
    initial
    begin  
        #12 cnt_in = 32'h000000A5;  
    end

    /* 仿真结束 */
    initial
    begin
	    #SIM_PERIOD $finish;
    end
    
    /* 监控 */
    /*initial
        $monitor("At time %t: clk(%b), rst_n(%b), cnt_in(%x), cnt_out(%x), int(%b)",
                  $time, clk, rst_n, cnt_in, cnt_out, int);
              */

    initial
        begin            
            $dumpfile("hyCntTb.vcd");
            $dumpvars(0, hyCntTb);
        end
endmodule
