if (!isInAir)
{
    //update running time
    runningTime += dT;
    if (runningTime >= updateTime)
    {
    runningTime = 0.0;
    //update animation frame
    scarfyRec.x = frame * scarfyRec.width;
    frame++;
    if (frame > 5)
    {
    frame = 0;
    }
        
    }
} 
