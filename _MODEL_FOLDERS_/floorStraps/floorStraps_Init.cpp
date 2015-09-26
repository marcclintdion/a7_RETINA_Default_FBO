      //------------------------------------------------------------------------------------------                                              
      #ifdef __APPLE__                                                                                                                          
/*      filePathName = [[NSBundle mainBundle] pathForResource:@"floorStraps_DOT3" ofType:@"bmp"];                                                  
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &floorStraps_NORMALMAP);                                                                                                     
      glBindTexture(GL_TEXTURE_2D, floorStraps_NORMALMAP);                                                                                          
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
      //---------------------                                                                                                                   
      filePathName = [[NSBundle mainBundle] pathForResource:@"floorStraps" ofType:@"png"];                                                       
      image = imgLoadImage([filePathName cStringUsingEncoding:NSASCIIStringEncoding]);                                                   
      glGenTextures(1, &floorStraps_TEXTUREMAP);                                                                                                       
      glBindTexture(GL_TEXTURE_2D, floorStraps_TEXTUREMAP);                                                                                            
      ConfigureAndLoadTexture(image->data,  image->width, image->height );                                                                      
      imgDestroyImage(image);                                                                                                                   
*/      
 
 
 
 
 #endif   


      //------------------------------------------------------------------------------------------                                              
      #ifdef WIN32                                                                                                                            
      loadTexture("_MODEL_FOLDERS_/floorStraps/floorStraps_DOT3.bmp",          floorStraps_NORMALMAP);                                                      
      loadTexture("_MODEL_FOLDERS_/floorStraps/floorStraps.png",               floorStraps_TEXTUREMAP);                                                        
      #endif                                                                                                                                    
      //------------------------------------------------------------------------------------------------------------//___LOAD_VBO               
      #include    "floorStraps.cpp"                                                                                                                
      glGenBuffers(1,              &floorStraps_VBO);                                                                                                
      glBindBuffer(GL_ARRAY_BUFFER, floorStraps_VBO);                                                                                                
      glBufferData(GL_ARRAY_BUFFER, sizeof(floorStraps), floorStraps, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ARRAY_BUFFER, 0);                                                                                                         
      //------------------------------------------------------------------------------------------------------------       
      #include    "floorStraps_INDICES.cpp"                                                                                                                
      glGenBuffers(1,              &floorStraps_INDICES_VBO);                                                                                                
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, floorStraps_INDICES_VBO);                                                                                                
      glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(floorStraps_INDICES), floorStraps_INDICES, GL_STATIC_DRAW);                                                                    
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);                                                                                                         
      //------------------------------------------------------------------------------------------------------------       
