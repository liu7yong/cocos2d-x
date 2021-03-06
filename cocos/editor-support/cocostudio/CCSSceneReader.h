/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __CCSSCENEREADER_H__
#define __CCSSCENEREADER_H__

#include "cocos2d.h"
#include "cocostudio/DictionaryHelper.h"


namespace cocostudio {

typedef void (cocos2d::Object::*SEL_CallFuncOD)(cocos2d::Object*, void*);
#define callfuncOD_selector(_SELECTOR) (SEL_CallFuncOD)(&_SELECTOR)

class SceneReader
{
public:
    /**
     * @js ctor
     */
    SceneReader(void);
    /**
     * @js NA
     * @lua NA
     */
    virtual ~SceneReader(void);

public:
    static SceneReader* getInstance();
    /**
     *  @js purge
     *  @lua destroySceneReader
     */
    static void destroyInstance();
    static const char* sceneReaderVersion();
    cocos2d::Node* createNodeWithSceneFile(const char *pszFileName);
	void setTarget(cocos2d::Object *rec, SEL_CallFuncOD selector);
	cocos2d::Node* getNodeByTag(int nTag);
private:
    cocos2d::Node* createObject(const rapidjson::Value& dict, cocos2d::Node* parent);
    void setPropertyFromJsonDict(const rapidjson::Value& dict, cocos2d::Node *node);
    bool readJson(const char *pszFileName, rapidjson::Document &doc);
	cocos2d::Node* nodeByTag(cocos2d::Node *pParent, int nTag);
private:
    static SceneReader* s_sharedReader;
	cocos2d::Object*    _pListener;
	SEL_CallFuncOD      _pfnSelector;
	cocos2d::Node*      _pNode;
};


}

#endif
