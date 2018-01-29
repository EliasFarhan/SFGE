
#Engine Zone
class Component:

    def Init(self):
        pass
    def Update(self, dt):
        pass
    def GetEulerAngle(self):
        pass
    def SetEulerAngle(self,eulerAngle):
        pass
    def GetPosition(self):
        pass
    def SetPosition(self,position):
        pass
    def GetScale(self):
        pass
    def SetScale(self,scale):
        pass

class ConfigManager:

    def Init(self):
        pass
    def LoadConfig(self,configFileName):
        pass



class GameObject:

    def Init(self):
        pass
    def Update(self, dt):
        pass
    def LoadGameObject(self,gameObjectFileName):
        pass


class Scene:

    def Init(self):
        pass
    def Update(self,dt):
        pass
    def LoadScene(self,sceneName):
        pass
    def Destroy(self):
        pass

#Input Zone
class InputManager:

    def Init(self):
        pass
    def Update(self,dt):
        pass