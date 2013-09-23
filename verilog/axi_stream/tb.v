////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:10:43 09/16/2013
// Design Name:   my_stream_ip
// Module Name:   E:/workspace/stream_ip/tb.v
// Project Name:  stream_ip
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: my_stream_ip
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////
`timescale 1ns / 1ps

module tb;
  parameter PERIOD = 10;
  parameter SIM_PERIOD = 1000;

  /* Inputs */
  reg ACLK;
  reg ARESETN;
  reg [63:0] S_AXIS_TDATA;
  reg [7:0] S_AXIS_TKEEP;
  reg S_AXIS_TVALID;
  reg S_AXIS_TLAST;
  reg M_AXIS_TREADY;

  /* Outputs */
  wire S_AXIS_TREADY;
  wire [63:0] M_AXIS_TDATA;
  wire [7:0] M_AXIS_TKEEP;
  wire M_AXIS_TVALID;
  wire M_AXIS_TLAST;

  /* Instantiate the Unit Under Test (UUT) */
  my_stream_ip uut (
      .ACLK(ACLK), 
      .ARESETN(ARESETN), 
      .S_AXIS_TDATA(S_AXIS_TDATA), 
      .S_AXIS_TKEEP(S_AXIS_TKEEP), 
      .S_AXIS_TVALID(S_AXIS_TVALID), 
      .S_AXIS_TREADY(S_AXIS_TREADY), 
      .S_AXIS_TLAST(S_AXIS_TLAST), 
      .M_AXIS_TDATA(M_AXIS_TDATA), 
      .M_AXIS_TKEEP(M_AXIS_TKEEP), 
      .M_AXIS_TVALID(M_AXIS_TVALID), 
      .M_AXIS_TREADY(M_AXIS_TREADY), 
      .M_AXIS_TLAST(M_AXIS_TLAST)
  );

  always
  begin
      ACLK = 1'b0;
      #(PERIOD/2) ACLK = 1'b1;
      #(PERIOD/2);
  end

  initial
  begin
      /* Initialize Inputs */
      ACLK = 0;
      ARESETN = 0;
      S_AXIS_TDATA = 0;
      S_AXIS_TKEEP = 0;
      S_AXIS_TVALID = 0;
      S_AXIS_TLAST = 0;
      M_AXIS_TREADY = 0;

      #100;
      ARESETN = 1;

      #100;
      S_AXIS_TDATA = 64'hFFEEDDCCBBAA9988;
      #100;
      S_AXIS_TVALID = 1;
      #100;
      S_AXIS_TKEEP = 8'b1;
      #100;
      S_AXIS_TLAST = 1;
      #100;
      M_AXIS_TREADY = 1;

  end 
  
  /* 仿真结束 */
  initial
  begin
      #SIM_PERIOD $finish;
  end 
  
  initial
  begin            
      $dumpfile("tb.vcd");
      $dumpvars(0, tb);
  end


 endmodule

