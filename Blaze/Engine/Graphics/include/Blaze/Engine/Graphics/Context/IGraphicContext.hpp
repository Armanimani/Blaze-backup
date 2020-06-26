#pragma once

namespace blaze
{
	class IGraphicContext
	{
	public:
		virtual ~IGraphicContext() = default;
		
		virtual void initialize() noexcept = 0;
		virtual void present() noexcept = 0;
		virtual void finalize() noexcept = 0;
	};
}
