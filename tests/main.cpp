#include <QtTest/QtTest>

#include "QDX/MathKit"
#include "QDX/TextKit"

class X;

class KitsTest : public QObject
{
	Q_OBJECT
private slots:
	void threshold();

	void capitalize();
	void hex();
	void formatFileSize();

private:

};

void KitsTest::threshold()
{
	QVERIFY(QDXMath::threshold(10, 16) == 6);
	QVERIFY(QDXMath::thresholdInBounds(14, 16, 1) == false);
	QVERIFY(QDXMath::thresholdInBounds(14, 15, 1));
	QVERIFY(QDXMath::thresholdInBounds(1.4, 1.6, 0.2) == false);
	QVERIFY(QDXMath::thresholdOutBounds(14, 16, 1));
}

void KitsTest::capitalize()
{
	QCOMPARE(QDXText::capitalize("abcdef"), QString("Abcdef"));
	QCOMPARE(QDXText::capitalize("hello worlD! (inlay)"), QString("Hello worlD! (Inlay)"));
	QCOMPARE(QDXText::capitalize("XYZ 123"), QString("XYZ 123"));
	QCOMPARE(QDXText::capitalize("привет"), QString("Привет"));
}

void KitsTest::hex()
{
	QCOMPARE(QDXText::hexInt(-436457), QString("FFF95717"));
	QCOMPARE(QDXText::hexUInt(1234567), QString("0012D687"));
	QCOMPARE(QDXText::hexShort(32456), QString("7EC8"));
	QCOMPARE(QDXText::hexChar('f'), QString("66"));
	QCOMPARE(QDXText::hex<qint64>(-54536547465685), QString("FFFFCE663876062B"));
	QCOMPARE(QDXText::hexInt(-436457, true), QString("1757F9FF"));
}

void KitsTest::formatFileSize()
{
	QCOMPARE(QDXText::formatFileSize(1023), QString("1023 B"));
	QCOMPARE(QDXText::formatFileSize(1024), QString("1.0 KB"));
	QCOMPARE(QDXText::formatFileSize(60 * 1024), QString("60.0 KB"));
	QCOMPARE(QDXText::formatFileSize(4536457347368), QString("4.1259 TB"));
}

QTEST_MAIN(KitsTest)
#include "main.moc"