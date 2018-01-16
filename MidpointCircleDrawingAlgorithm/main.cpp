//
//  main.cpp
//  assignment_1_Oct_1
//
//  Created by Jingnong Wang on 10/1/17.
//  Copyright © 2017 Jingnong Wang. All rights reserved.
//

#include <GLFW/glfw3.h>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main( void ) {
  GLFWwindow *window;
  
  // Initialize the library
  
  if ( !glfwInit( ) )    {
    
    return -1;
  }
  
  
  
  // Create a windowed mode window and its OpenGL context
  
  window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "Assignment1: draw a circle", NULL, NULL );
  
  
  
  if ( !window )
    
  {
    
    glfwTerminate( );
    
    return -1;
    
  }
  
  // Make the window's context current
  
  glfwMakeContextCurrent( window );
  
  
  
  glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1 ); // set projection area

  // Loop until the user closes the window
  
  while ( !glfwWindowShouldClose( window ) )
    
  {
    
    glClear( GL_COLOR_BUFFER_BIT );

    // Render OpenGL here
    // mid-point algorithm
    
    // radius
    int R = 100;
    // position of first point
    int x = 0;
    int y = R;
    // position of the center of circle
    int offset_x = 320;
    int offset_y = 240;
    // d = (x^2 + y^2) - R^2
    float d = 5/4 - R;
    
    while(x < y) {
      // draw (x, y) and the other seven symmetric points
      glBegin(GL_POINTS);
      glVertex2i(x + offset_x, y + offset_y); // up right part1
      glVertex2i(x + offset_x, -y + offset_y); // down right part1
      glVertex2i(-x + offset_x, y + offset_y); // up left part1
      glVertex2i(-x + offset_x, -y + offset_y); // down left part1
      glVertex2i(y + offset_x, x + offset_y); // up right part2
      glVertex2i(y + offset_x, -x + offset_y); // down right part2
      glVertex2i(-y + offset_x, x + offset_y); // up left part2
      glVertex2i(-y + offset_x, -x + offset_y); // down left part2
      glEnd();
      
      // calculate next d, x, y
      if(d < 0) {
        d += x * 2 + 3;
        x += 1;
      } else {
        d +=2 * (x - y) + 5;
        x += 1;
        y -= 1;
      }
    }

    // Swap front and back buffers
    
    glfwSwapBuffers( window );
    
    
    
    // Poll for and process events
    
    glfwPollEvents( );
    
  }
  
  
  
  glfwTerminate( );
  
  return 0;
  
}
