module my_stream_ip
(
    ACLK,

    ARESETN,
    S_AXIS_TDATA,
    S_AXIS_TKEEP,
    S_AXIS_TVALID,
    S_AXIS_TREADY,
    S_AXIS_TLAST,

    M_AXIS_TDATA,
    M_AXIS_TKEEP,
    M_AXIS_TVALID,
    M_AXIS_TREADY,
    M_AXIS_TLAST
);

input            ACLK;
input            ARESETN;

input[63:0]      S_AXIS_TDATA;
input[7:0]       S_AXIS_TKEEP;
input            S_AXIS_TVALID;
output           S_AXIS_TREADY;
input            S_AXIS_TLAST;

output[63:0]     M_AXIS_TDATA;
output[7:0]      M_AXIS_TKEEP;
output           M_AXIS_TVALID;
input            M_AXIS_TREADY;
output           M_AXIS_TLAST;

reg [63:0] out_reg;
reg [7:0] keep_reg;

assign S_AXIS_TREADY    = !ARESETN;
assign M_AXIS_TVALID    = !ARESETN;

assign M_AXIS_TLAST     = !ARESETN;

assign M_AXIS_TKEEP[7:0]= keep_reg[7:0];
assign M_AXIS_TDATA[63:0]= out_reg[63:0];

always @(posedge ACLK)
begin
  if(!ARESETN)
  begin
    out_reg[63:0] <= 64'b0;
    keep_reg[7:0] <= 8'b0;
  end
  else
  begin
    if(M_AXIS_TREADY == 1)
    begin
      out_reg[63:0] <= S_AXIS_TDATA[63:0];
      keep_reg[7:0] <= S_AXIS_TKEEP[7:0];
    end
  end
end
endmodule

