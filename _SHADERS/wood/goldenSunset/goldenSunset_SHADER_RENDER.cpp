
MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
LoadIdentity(lightMatrix);                                                                                                                                                
InvertMatrix(lightMatrix, modelView);                                                                                                                                     
//---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
LoadIdentity(textureMatrix);
//Translate(textureMatrix, shadowsPositionOffset[0], shadowsPositionOffset[1], shadowsPositionOffset[2]);
//Scale(textureMatrix, scaleShadows, scaleShadows, scaleShadows);   



glUseProgram(goldenSunset_SHADER);          
//------------------------------------------------------------------------------         
glVertexAttribPointer(0,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                  
glEnableVertexAttribArray(0);	                                                                                              
glVertexAttribPointer(1,     3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                 
glEnableVertexAttribArray(1);	                                                                                          
glVertexAttribPointer(2,     2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                 
glEnableVertexAttribArray(2);                                                                                               
//------------------------------------------------------------------------------------------------                                
glUniform4f(UNIFORM_LIGHT_POSITION_01_goldenSunset,          goldenSunset_LIGHT_POSITION_01[0],                       
            goldenSunset_LIGHT_POSITION_01[1],                       
            goldenSunset_LIGHT_POSITION_01[2],                       
            goldenSunset_LIGHT_POSITION_01[3]);                      

                            
glUniform1f(UNIFORM_shininess_goldenSunset,                  shininess_goldenSunset);
glUniform1f(UNIFORM_ambient_goldenSunset,                    ambient_goldenSunset);   
glUniform1f(UNIFORM_counter_goldenSunset,                    globalLinearAttenuation);                  
//------------------------------------------------------------------------------------------------
glUniformMatrix4fv(UNIFORM_MODELVIEW_goldenSunset,       1, 0,         modelView);                                             
glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_goldenSunset,   1, 0,         mvpMatrix);                                   
//---------------     
glUniformMatrix4fv(UNIFORM_viewMatrix_goldenSunset,      1, 0,         viewMatrix);     
//---------------     
glUniformMatrix4fv(UNIFORM_SHADOW_PROJ_goldenSunset,     1, 0,         ProjectionShadow);
glUniformMatrix4fv(UNIFORM_modelViewShadow_goldenSunset, 1, 0,         modelViewShadow);
//---------------                                                                                                                                      
//glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_INVERSE_goldenSunset, 1, 0, ModelViewProjectionInverse);                            
glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_goldenSunset,    1, 0,         lightMatrix);                                           
glUniformMatrix4fv(UNIFORM_TEXTURE_MATRIX_goldenSunset,  1, 0,         textureMatrix);                                       
//-------------------------------------------------------------------------------------------------                                
//glUniform1i(UNIFORM_ShadowTexture_goldenSunset,  3);                                                                      
glUniform1i(UNIFORM_TEXTURE_DOT3_goldenSunset,   1);                                                                        
glUniform1i(UNIFORM_TEXTURE_goldenSunset,        0);                                                        
//====================================================================================================================
