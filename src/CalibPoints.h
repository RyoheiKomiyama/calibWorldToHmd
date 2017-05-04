//
//  CalibPoints.h
//  calibWorldToHmd
//
//  Created by ryoheikomiyama on 2017/05/04.
//
//
#pragma once

class CalibPoints {
    
    ofMesh mesh;
    int index;
    
public:
    CalibPoints() {
        
        // vertices
        vector<ofVec3f> vertices = {
            ofVec3f(0, 0, 0)+pos,
            ofVec3f(0, box_size, 0)+pos,
            ofVec3f(box_size, box_size, 0)+pos,
            ofVec3f(box_size, 0, 0)+pos,
            ofVec3f(0, 0, box_size)+pos,
            ofVec3f(0, box_size, box_size)+pos,
            ofVec3f(box_size, box_size, box_size)+pos,
            ofVec3f(box_size, 0, box_size)+pos
        };
        mesh.addVertices(vertices);
        
        vector<ofFloatColor> colors;
        for (int i = 0; i < vertices.size(); i++) {
            colors.push_back(color);
        }
        mesh.addColors(colors);
        
        // triangle
        mesh.addTriangle(0, 1, 2);
        mesh.addTriangle(0, 2, 3);
        mesh.addTriangle(4, 5, 1);
        mesh.addTriangle(4, 1, 0);
        mesh.addTriangle(7, 6, 5);
        mesh.addTriangle(7, 5, 4);
        mesh.addTriangle(3, 2, 6);
        mesh.addTriangle(3, 6, 7);
        mesh.addTriangle(1, 5, 6);
        mesh.addTriangle(1, 6, 2);
        mesh.addTriangle(4, 0, 3);
        mesh.addTriangle(4, 3, 7);
    }
    
    void update() {}
    
    void draw() {
        mesh.draw();
    }
    
    void drawWireFrame() {
        mesh.drawWireframe();
    }
    
};
