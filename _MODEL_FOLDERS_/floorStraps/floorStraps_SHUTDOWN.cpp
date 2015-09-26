                    if(floorStraps_NORMALMAP != 0)                                                                                        
                    {                                                                                                              
                            glDeleteTextures(1, &floorStraps_NORMALMAP);                                                                  
                            floorStraps_NORMALMAP = 0;                                                                                    
                    }                                                                                                              
                    if(floorStraps_TEXTUREMAP  != 0)                                                                                      
                    {                                                                                                              
                            glDeleteTextures(1, &floorStraps_TEXTUREMAP);                                                                 
                            floorStraps_TEXTUREMAP  = 0;                                                                                  
                    }                                                                                                              
                    if(floorStraps_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &floorStraps_VBO);                                                                         
                            floorStraps_VBO  = 0;                                                                                         
                    }                                                                                                              
                    if(floorStraps_INDICES_VBO  != 0)                                                                                             
                    {                                                                                                              
                            glDeleteBuffers(1, &floorStraps_INDICES_VBO);                                                                         
                            floorStraps_INDICES_VBO  = 0;                                                                                         
                    }                                                                                                              
