glBindBuffer(GL_ARRAY_BUFFER, floorStraps_VBO);                                                                                                                                
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, floorStraps_INDICES_VBO);                                                                                                                                
      
      
        Translate(modelView, floorStraps_POSITION[0], floorStraps_POSITION[1], floorStraps_POSITION[2]);                                                                                         
        Rotate(modelView, floorStraps_ROTATE[0], floorStraps_ROTATE[1], floorStraps_ROTATE[2], floorStraps_ROTATE[3]+= 1.0); 

//=================================================================================================================         
SelectShader(shaderNumber);
//=================================================================================================================
                                                                
    glActiveTexture ( GL_TEXTURE1 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, floorStraps_NORMALMAP);                                                                                                                          
    //---                                                                                                                                                                     
    glActiveTexture (GL_TEXTURE0);                                                                                                                                            
    glBindTexture(GL_TEXTURE_2D, floorStraps_TEXTUREMAP);                                                                                                                            
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__DRAW              
    glDrawElements(GL_TRIANGLES, 2286, GL_UNSIGNED_INT, 0);                                                                                                     

glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                                                
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);  