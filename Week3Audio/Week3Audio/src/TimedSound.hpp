//
//  TimedSound.hpp
//  cim594_18_audioout
//
//  Created by Clay Ewing on 2/8/17.
//
//

#ifndef TimedSound_hpp
#define TimedSound_hpp

#include "ofMain.h"

class TimedSound{
    
public:
    
        
    TimedSound(int Row);
    virtual ~TimedSound(){};
    
    int row;
	float yPos;
	bool played;
    void draw();
    void update();
    
protected:
private:
};

#endif /* TimedSound_hpp */
