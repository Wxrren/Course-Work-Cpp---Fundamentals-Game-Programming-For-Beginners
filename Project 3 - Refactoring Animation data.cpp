// bit's of code taken from different areas of my overrall work space to show what ive done. I created a function which updates my animation time for me to have cleaner code. 

//Performing ground check function
bool isOnGround(AnimData data, int windowheight)
{
    return data.pos.y >= windowheight - data.rec.height;
}

// Scarfy animation update function.
AnimData updateAnimData(AnimData data, float deltaTime, int maxframe)
{
    // update running time
    data.runningTime += deltaTime;
    if (data.runningTime >= data.updateTime)
    {
        data.runningTime = 0.0;
        // Update animation frame
        data.rec.x = data.frame * data.rec.width;
        data.frame++;
        if (data.frame > 7 > maxframe)
        {
            data.frame = 0;
        }
        
    }
    return data;
}

//nebula animation update function.

AnimData UpdateNebulaData(AnimData data, float deltaTime, int MaxFrame)
{
       //update nebula running time
        data.runningTime += deltaTime;
        if (data.runningTime >= data.updateTime)
        {
       data.runningTime = 0.0;
        // update nebula animation frame
        data.rec.x = data.frame * data.rec.width;
        data.frame++;
        if (data.frame > 7)
        {
            data.frame = 0;}
        } 
return data;

}


//perform ground check
if (isOnGround(scarfyData, windowDimensions[1]))
{
   velocity = 0;
   isInAir = false;
}
else
{
    velocity += gravity * dT;
    isInAir = true;
}

// Updating scarfy animation frames
if (!isInAir)
{
   scarfyData = updateAnimData(scarfyData, dT, 5);
   
// Nebula's running time and animation frames
        for (int i = 0; i < sizeOfNebulas; i++ )
        {
    multipleNebulas[i] = updateAnimData(multipleNebulas[i], dT, 7);
        }
}
