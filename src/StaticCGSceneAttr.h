//
//  StaticCGSceneAttr.h
//  demoViewer
//
//  Created by ryoheikomiyama on 2017/04/23.
//
//

#ifndef StaticCGSceneAttr_h
#define StaticCGSceneAttr_h

// meter or centimeter
#define METERSCALE
#ifdef METERSCALE
#define SCALE 100.0
#else
#define SCALE 1.0
#endif

// 1 or 255
#define COLOR1
#ifdef COLOR1
#define COLORSCALE 255.0
#else
#define COLORSCALE 1.0
#endif


#include "ofMain.h"

namespace scgsa {

	class ColorBox {

		ofMesh mesh;
		ofFloatColor color;
		ofVec3f pos;

	public:
		ColorBox(ofFloatColor color, ofVec3f pos) {

			// color, pos
			this->color = color;
			this->pos = pos;

			// vertices
			float box_size = 60 / SCALE;
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


	class Grass {

		ofMesh mesh;
		ofFloatColor color;
        ofVec3f pos;

	public:
		Grass(ofFloatColor color, ofVec3f pos) {

			this->color = color;
            this->pos = pos;

			// vertices
			vector<ofVec3f> vertices = {
                ofVec3f(0, 0, 0) + pos,
                ofVec3f(200/SCALE, 0, 0) + pos,
                ofVec3f(200/SCALE, 0, 100/SCALE) + pos,
                ofVec3f(0, 0, 100/SCALE) + pos
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
		}

		void update() {}

		void draw() {
			mesh.draw();
		}

		void drawWireFrame() {
			mesh.drawWireframe();
		}


	};




	class StaticCGSceneAttr {

		vector<ColorBox> boxes;
		vector<Grass> grasses;

	public:
		StaticCGSceneAttr() {
			ColorBox box_r(ofFloatColor(200 / COLORSCALE, 100 / COLORSCALE, 100 / COLORSCALE), ofVec3f(0, 1/SCALE, -160 / SCALE));
			ColorBox box_y(ofFloatColor(210 / COLORSCALE, 210 / COLORSCALE, 100 / COLORSCALE), ofVec3f(-200 / SCALE, 1/SCALE, -60 / SCALE));
			ColorBox box_b(ofFloatColor(70 / COLORSCALE, 100 / COLORSCALE, 130 / COLORSCALE), ofVec3f(140 / SCALE, 1/SCALE, 40 / SCALE));
			boxes.push_back(box_r);
			boxes.push_back(box_y);
			boxes.push_back(box_b);
			ColorBox box_r_black(ofFloatColor(0, 0, 0), ofVec3f(0, 1/SCALE, -160 / SCALE));
			ColorBox box_y_black(ofFloatColor(0, 0, 0), ofVec3f(-200 / SCALE, 1/SCALE, -60 / SCALE));
			ColorBox box_b_black(ofFloatColor(0, 0, 0), ofVec3f(140 / SCALE, 1/SCALE, 40 / SCALE));
			boxes.push_back(box_r_black);
			boxes.push_back(box_y_black);
			boxes.push_back(box_b_black);

            for(int i=0; i<2; i++){
                for(int j=0; j<4; j++){
                    Grass grass(ofFloatColor(80 / COLORSCALE, 120 / COLORSCALE, 60 / COLORSCALE), ofVec3f(2*(i-1)*100/SCALE, 0, (j-2)*100/SCALE));
                    grasses.push_back(grass);
                }
            }
            for(int i=0; i<2; i++){
                for(int j=0; j<4; j++){
                    Grass grass_black(ofFloatColor(0, 0, 0), ofVec3f(2*(i-1)*100/SCALE, 0, (j-2)*100/SCALE));
                    grasses.push_back(grass_black);
                }
            }
		}

		void update() {
			for (auto& box : boxes) {
				box.update();
			}
			for (auto& grass : grasses) {
				grass.update();
			}
		}

		void draw() {
			for (int i = 0; i < 3; i++) {
				boxes[i].draw();
			}
            for (int i=0; i<8; i++){
                grasses[i].draw();
            }
		}

		void drawWireFrame() {
			for (int i = 0; i < 3; i++) {
				boxes[i].drawWireFrame();
			}
            for (int i=0; i<8; i++){
                grasses[i].drawWireFrame();
            }
		}

		void drawBlackWireFrame() {
			for (int i = 3; i < 6; i++) {
				boxes[i].drawWireFrame();
			}
            for (int i=8; i<16; i++){
                grasses[i].drawWireFrame();
            }
		}

	};
    
    
    
    class CalibPoints{
    public:
        
        struct pointset{
            pointset(ofVec3f v): world_point(v),
				world_ori_y(ofVec3f(0, 0, 1)),
				world_ori_z(ofVec3f(0, -1, 0)) {}
			ofVec3f world_point;
			ofVec3f world_ori_y;
			ofVec3f world_ori_z;
			ofVec3f vive_point;
			ofVec3f vive_ori_y;
			ofVec3f vive_ori_z;
			ofVec3f rotvec;
			float angle;
			bool isFinished = false;
        };
        
        vector<pointset> pointsets;
        int target = 0;
        ofColor color = ofColor(127, 127, 127, 127);
        ofColor finished_color = ofColor(0, 255, 0, 127);
        ofColor target_color = ofColor(255, 0, 0, 127);
        
    public:
        CalibPoints() {
            //red
            pointsets.push_back(pointset(ofVec3f(0, 60, -100)/SCALE));
            pointsets.push_back(pointset(ofVec3f(60, 60, -100)/SCALE));
            pointsets.push_back(pointset(ofVec3f(60, 60, -160)/SCALE));
            pointsets.push_back(pointset(ofVec3f(0, 60, -160)/SCALE));
            //yellow
            pointsets.push_back(pointset(ofVec3f(-200, 60, 0)/SCALE));
            pointsets.push_back(pointset(ofVec3f(-140, 60, 0)/SCALE));
            pointsets.push_back(pointset(ofVec3f(-140, 60, -60)/SCALE));
            pointsets.push_back(pointset(ofVec3f(-200, 60, -60)/SCALE));
            //blue
            pointsets.push_back(pointset(ofVec3f(140, 60, 100)/SCALE));
            pointsets.push_back(pointset(ofVec3f(200, 60, 100)/SCALE));
            pointsets.push_back(pointset(ofVec3f(200, 60, 40)/SCALE));
            pointsets.push_back(pointset(ofVec3f(140, 60, 40)/SCALE));
        }
        
        void update(){
            uint64_t t = (ofGetElapsedTimeMillis()/300)%2;
            if(t==0){
                if(pointsets[target].isFinished==true){
                    target_color = finished_color;
                }
                else{
                    target_color = ofColor(255, 0, 0, 127);
                }
            }
            else if(t==1){
                target_color = color;
            }
        }
        
        void draw(){
            for(int i=0; i<pointsets.size(); i++){
                if(i!=target){
                    ofPushStyle();
                    if(pointsets[i].isFinished==true) ofSetColor(finished_color);
                    else ofSetColor(color);
                    ofDrawSphere(pointsets[i].world_point, 5/SCALE);
                    ofPopStyle();
                }
                if(i==target){
                    ofPushStyle();
                    ofSetColor(target_color);
                    ofDrawSphere(pointsets[i].world_point, 5/SCALE);
                    ofPopStyle();
                }
				if (pointsets[target].isFinished == true) {
					ofPushMatrix();
					ofScale(-1, 1, -1);
					ofTranslate(pointsets[i].vive_point);
					ofRotate(pointsets[i].angle, pointsets[i].rotvec.x, 
						pointsets[i].rotvec.y, pointsets[i].rotvec.z);
					ofDrawAxis(10/SCALE);
					ofPopMatrix();					
				}
            }
        }

		void setValue(ofVec3f pos, ofVec3f rotvec, float angle, ofVec3f ori_y, ofVec3f ori_z) {
			pointsets[target].vive_point = pos;
			pointsets[target].vive_ori_y = ori_y;
			pointsets[target].vive_ori_z = ori_z;
			pointsets[target].rotvec = rotvec;
			pointsets[target].angle = angle;
			pointsets[target].isFinished = true;
			nextTarget();
		}
        
        void nextTarget(){
            target++;
            if(target==pointsets.size()) target=0;
        }
    };

    
}

#endif /* StaticCGSceneAttr_h */
