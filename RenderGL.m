
    
    glClearColor( 0.0f, 0.0f, 0.0f, 0.5f );
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    
    //=====================================================================================================================  
    
    PerspectiveMatrix(projection, 45,(float)_viewWidth / (float)_viewHeight, 0.1, 10000);
    Rotate(projection, -90.0, 0.0, 0.0, 1.0);//_____FOR_iOS_LANDSCAPE_VIEW 
    
    
    
    //======================================================================================================================================   
    rotation                   += 1.0;   
    
    glUseProgram(marcLeftUpperArm_SHADER);  
    glBindBuffer(GL_ARRAY_BUFFER, marcLeftUpperArm_VBO);
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__MODEL 
    LoadIdentity(modelView);
    Translate(modelView, 0.0, 0.0, -2.0);    
    Translate(modelView, marcLeftUpperArm_POSITION[0], marcLeftUpperArm_POSITION[1], marcLeftUpperArm_POSITION[2]);  
    Rotate(modelView, rotation, 1.3, 0.9, 1.0);//--MODEL
    MultiplyMatrix(mvp, projection, modelView); 
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT 
    LoadIdentity(lightMatrix);
    InvertMatrix(lightMatrix, modelView);
    Translate(lightMatrix, 1.0, -10.0, 2.0);         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__ATTRIBUTES 
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 24, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(0);	
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 24, BUFFER_OFFSET(12));
    glEnableVertexAttribArray(1); 
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS       
    glUniform4f(UNIFORM_marcLight_POSITION_01,marcLightPosition_01[0],marcLightPosition_01[1],marcLightPosition_01[2],marcLightPosition_01[3]);    
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_marcLeftUpperArm, 1, 0,  mvp);
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_marcLeftUpperArm, 1, 0,  lightMatrix);        
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__TEXTURES 
    glActiveTexture ( GL_TEXTURE1 );
    glBindTexture(GL_TEXTURE_2D, normalMap[0]);     
    glUniform1i (UNIFORM_marc_TEXTURE_DOT3, 1 );    
    //---
    glActiveTexture (GL_TEXTURE0); 
    glBindTexture(GL_TEXTURE_2D, textureMap[0]);    
    glUniform1i (UNIFORM_marc_TEXTURE, 0 );    
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW  
    glDrawArrays(GL_TRIANGLES, 0, 489);   
    //=======================================================================================================================================    
    

