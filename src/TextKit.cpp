#include "TextKit.h"

#include <memory>

QString QDXText::capitalize(const QString &input)
{
	QString result = input;
	bool capitalize = true;
	bool last_was_letter = false;
	QChar *first = nullptr;
	for (QChar &ch : result) {
		if (ch.isLetterOrNumber()) {
			last_was_letter = true;
			if (capitalize == false) {
				continue;
			}
			if (first == nullptr) {
				if (ch.isNumber()) {
					capitalize = false;
					continue;
				} else {
					first = &ch;
				}
			}
			if (ch.isUpper()) {
				capitalize = false;
			}
		} else {
			if (first) {
				if (capitalize) {
					*first = first->toUpper();
				}
				first = nullptr;
			}
			capitalize = ch != '\'' || last_was_letter == false;
			last_was_letter = false;
		}
	}
	if (first && capitalize) {
		*first = first->toUpper();
	}
	return result;
}

static const char hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

QString QDX::TextKit::hexString(const char *source, int length, bool little_endian)
{
	if (length < 0) {
		length = int(strlen(source));
	}

	std::unique_ptr<char []> result(new char[length * 2]);

	return hexString(source, result.get(), length, little_endian);
}

QString QDX::TextKit::hexString(const char *source, char *destination, int length, bool little_endian)
{
	if (little_endian) {
		for (int i = 0; i < length; ++i) {
			destination[i * 2]     = hex_chars[(*source & 0xF0) >> 4];
			destination[i * 2 + 1] = hex_chars[*source & 0x0F];
			++source;
		}
	} else {
		for (int i = length - 1; i >= 0; --i) {
			destination[i * 2]     = hex_chars[(*source & 0xF0) >> 4];
			destination[i * 2 + 1] = hex_chars[*source & 0x0F];
			++source;
		}
	}
	return QString::fromLatin1(destination, length * 2);
}

QString QDXText::hexInt(int source, bool little_endian)
{
	return hex(source, little_endian);
}

QString QDXText::hexUInt(uint source, bool little_endian)
{
	return hex(source, little_endian);
}

QString QDXText::hexShort(short source, bool little_endian)
{
	return hex(source, little_endian);
}

QString QDXText::hexChar(char source)
{
	char result[2];
	result[0] = hex_chars[source & 0x0F];
	result[1] = hex_chars[(source >> 4) & 0x0F];
	return QString::fromLatin1(result, 2);
}

static const qint64 kb = 1024;
static const qint64 mb = 1024 * kb;
static const qint64 gb = 1024 * mb;
static const qint64 tb = 1024 * gb;

QString QDXText::formatFileSize(qint64 size)
{
	if (size >= tb) {
		return QString::number(qreal(size) / tb, 'f', 4) + " TB";
	}
	if (size >= gb) {
		return QString::number(qreal(size) / gb, 'f', 3) + " GB";
	}
	if (size >= mb) {
		return QString::number(qreal(size) / mb, 'f', 2) + " MB";
	}
	if (size >= kb) {
		return QString::number(qreal(size) / kb, 'f', 1) + " KB";
	}
	return QString::number(size) + " B";
}