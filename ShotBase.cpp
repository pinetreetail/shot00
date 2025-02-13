#include "ShotBase.h"
#include "DxLib.h"


namespace
{
	
}

ShotBase::ShotBase()
{
	m_handle = -1;
	m_pos.x = 0.0f;
	m_pos.y = 0.0f;

	m_vec.x = 0.0f;
	m_vec.y = 0.0f;

	m_isExist = false;


}

ShotBase::~ShotBase()
{

}

void ShotBase::start(Vec2 pos)
{
	m_isExist = true;
	m_pos = pos;

	m_vec.x = kShotSpeed;
	m_vec.y = 0.0f;
}

void ShotBase::update()
{
	if (!m_isExist) return;

	m_pos += m_vec;

	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}
// �\��
void ShotBase::draw()
{
	if (!m_isExist) return;

	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}
