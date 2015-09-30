                          
                          
                           glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));
                           glEnableVertexAttribArray(0);	
                           glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));
                           glEnableVertexAttribArray(1);                             
                           
                           glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));
                           glEnableVertexAttribArray(2);               
                           //--------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS
                           glUniform4f(UNIFORM_darkness_shadow, darkness_shadow[0],  darkness_shadow[1], darkness_shadow[2], darkness_shadow[3]);         
                           //--------------
                           glUniformMatrix4fv(UNIFORM_MODELVIEW_shadow, 1, 0,      LightModelViewMatrix);
                           glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_shadow, 1, 0,  ModelViewProjection);
                           glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_shadow,  1, 0,  LightMatrix);  
