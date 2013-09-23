`timescale 10ps/1ps

module hyCnt(clk, rst_n, cnt_in, cnt_out, int);
    parameter C_WIDTH = 32;

    // 时钟 复位 
    input clk;
    wire clk;
    input rst_n;
    wire rst_n;

    // 初始值
    input[C_WIDTH:1] cnt_in;
    wire[C_WIDTH:1] cnt_in;

    // 输出值 及 中断
    output[C_WIDTH:1] cnt_out;
    wire[C_WIDTH:1] cnt_out;
    output int;
    wire int;

    // 计数器 内部 寄存器
    reg[C_WIDTH:1] cnt_reg;

    always @ (posedge clk)
    begin
        if((!rst_n) || (int))    // 复位时置初值,计数到期时置初值
	begin
            cnt_reg[C_WIDTH:1] <= cnt_in[C_WIDTH:1];
	end
	else			// 计数
	begin
            cnt_reg[C_WIDTH:1] <= cnt_reg[C_WIDTH:1] - 1'b1;
	end
    end

    assign #5 int = !(|cnt_reg[C_WIDTH:1]) & rst_n;
    assign #1 cnt_out[C_WIDTH:1] = cnt_reg[C_WIDTH:1];

endmodule
