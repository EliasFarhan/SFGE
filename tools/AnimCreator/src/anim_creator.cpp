/*
MIT License

Copyright (c) 2018 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <anim_creator.h>

#include <engine/engine.h>
#include <utility/log.h>

#include <extensions/python_extensions.h>

namespace sfge::tools
{
	void AnimCreator::Init()
	{
	    Log::GetInstance()->Msg("Init Anim Creator");
		m_AnimationManager.Init();
		m_TextureManager.Init();
		m_GraphicsManager.Init(this);

		m_isInit = true;
	}
	void AnimCreator::Update(float dt)
	{
		if (!m_isInit)
			Init();

	    (void) dt;
	    Log::GetInstance()->Msg("Update Anim Creator");
		m_GraphicsManager.Update(dt);
	}
	void AnimCreator::Draw()
	{
		if (!m_isInit)
			return;

	    Log::GetInstance()->Msg("Draw Anim Creator");
		m_GraphicsManager.Draw();
	}
	GraphicsManager* AnimCreator::GetGraphicsManager()
	{
		return &m_GraphicsManager;
	}
	TextureManager* AnimCreator::GetTextureManager()
	{
		return &m_TextureManager;
	}
	AnimationManager* AnimCreator::GetAnimationManager()
	{
		return &m_AnimationManager;
	}
}