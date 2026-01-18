#include "InstanceManager.h"

InstanceManager* InstanceManager::m_instance = nullptr;

InstanceManager* InstanceManager::getInstance() {
	if (!m_instance) {
		m_instance = new InstanceManager();
	}
	return m_instance;
}