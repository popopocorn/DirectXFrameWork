#include "stdafx.h"
#include "GameObject.h"
#include"Shader.h"

CGameObject::CGameObject()
{
	XMStoreFloat4x4(&m_xmf4x4world, XMMatrixIdentity());
}