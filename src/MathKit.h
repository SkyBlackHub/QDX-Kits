#ifndef MATHTOOLS_H
#define MATHTOOLS_H

namespace QDX {

	namespace MathKit {

		template <typename T>
		inline T threshold(const T &value1, const T &value2)
		{
			if (value1 > value2) {
				return value1 - value2;
			}
			return value2 - value1;
		}

		template <typename T>
		inline bool thresholdOutBounds(const T &value1, const T &value2, const T &threshold)
		{
			if (value1 > value2) {
				return (value1 - value2) > threshold;
			}
			return (value2 - value1) > threshold;
		}

		template <typename T>
		inline bool thresholdInBounds(const T &value1, const T &value2, const T &threshold)
		{
			if (value1 > value2) {
				return (value1 - value2) <= threshold;
			}
			return (value2 - value1) <= threshold;
		}

	}

} // namespace QDX

namespace QDXMath = QDX::MathKit;

#endif // MATHTOOLS_H