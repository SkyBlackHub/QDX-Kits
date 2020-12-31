#ifndef TEXTTOOLS_H
#define TEXTTOOLS_H

#include <QString>

namespace QDX {

	namespace TextKit {

		QString capitalize(const QString &input);

		template <typename T>
		QString hex(const T &source, bool little_endian = false);

		QString hexString(const char *source, int length = -1, bool little_endian = false);
		QString hexString(const char *source, char *destination, int length, bool little_endian = false);

		QString hexInt(int source, bool little_endian = false);
		QString hexUInt(uint source, bool little_endian = false);
		QString hexShort(short source, bool little_endian = false);
		QString hexChar(char source);

		QString formatFileSize(qint64 size);

	}

} // namespace QDX

namespace QDXText = QDX::TextKit;

template <typename T>
QString QDXText::hex(const T &source, bool little_endian)
{
	char result[sizeof(T) * 2];
	return hexString(reinterpret_cast<const char *>(&source), result, sizeof(T), little_endian);
}

#endif // TEXTTOOLS_H