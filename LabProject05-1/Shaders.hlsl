float4 VSMain(uint nVertexID : SV_VertexID) : SV_POSITION
{
    float4 output = (float4) 0;
    
    switch (nVertexID)
    {
        case 0:
            output = float4(-1.0f, 1.0f, 0.0f, 1.0f);
            break;
        case 1:
            output = float4(1.0f, 1.0f, 0.0f, 1.0f);
            break;
        case 2:
            output = float4(1.0f, -1.0f, 0.0f, 1.0f);
            break;
        case 3:
            output = float4(-1.0f, 1.0f, 0.0f, 1.0f);
            break;
        case 4:
            output = float4(1.0f, -1.0f, 0.0f, 1.0f);
            break;
        case 5:
            output = float4(-1.0f, -1.0f, 0.0f, 1.0f);
            break;
        
    }
    
    return output;
}

#define FRAME_BUFFER_WIDTH  640.0f;
#define FRAME_BUFFER_HEIGHT 480.0f;


float4 PSMain(float4 input : SV_Position) : SV_Target
{
    float4 cColor = float4(0.0f, 0.0f, 0.0f, 1.0f);
    cColor.r = input.x / FRAME_BUFFER_WIDTH;
    return cColor;
}   