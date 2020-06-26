#pragma once

#include <Blaze/Engine/Graphics/Context/IGraphicContext.hpp>
#include <Blaze/Engine/Graphics/Context/GraphicSpecification.hpp>
#include <Windows.h>

#include "Blaze/Engine/PlatformDirectX12/common.hpp"

namespace blaze
{
	class DX12GraphicContext final: public IGraphicContext
	{
	public:
		DX12GraphicContext(const GraphicSpecification& specification, void* window_handle);

		void initialize() noexcept override;
		void present() noexcept override;
		void finalize() noexcept override;
	private:
		HWND handle{};
		Microsoft::WRL::ComPtr<ID3D12Device6> device{};
	};
}