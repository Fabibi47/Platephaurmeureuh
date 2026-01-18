#pragma once
class InstanceManager
{
private:
	static InstanceManager* m_instance;
protected:
	InstanceManager() {};
public:
	static InstanceManager* getInstance();
};

