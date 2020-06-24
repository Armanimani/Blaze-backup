#pragma once

#include <Blaze/Engine/Graphics/Context/IGraphicContext.hpp>
#include <Blaze/Engine/Graphics/Context/GraphicSpecification.hpp>
#include <Windows.h>

namespace blaze
{
	class DX12GraphicContext final: public IGraphicContext
	{
	public:
		DX12GraphicContext(const GraphicSpecification& specification, void* window_handle);
	private:
		HWND handle{};
	};
}