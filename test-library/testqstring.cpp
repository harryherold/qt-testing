/*
 * testqstring.cpp
 *
 * Copyright 2013 Christian Herold <harryherold@googlemail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <QtTest/QtTest>

class Math
{
private:

public:
  int multInt( int , int );
  int addInt( int , int );
};

int Math::multInt( int x , int y )
{
  return x * y;
}

int Math::addInt( int x , int y )
{
  return x + y;
}

class TestQString: public QObject
{
  Q_OBJECT

private slots:
  void initTestCase( void );
  void cleanupTestCase( void );

  void testMathMult( void );
  void testMathAdd( void );
  void toUpper( void );
  void toUpper_data( void );
  void toUpperMore( void );
  void firstBenchmark( void );
};

void TestQString::testMathAdd( void )
{
  Math m1;
  if( m1.addInt( 1 , 1 ) != 2 )
    QFAIL("the computer can't calculate !!");
}
void TestQString::testMathMult( void )
{
  Math m1;
  QSKIP( "Can't do anything because i have no beer !!" , SkipAll );
  QCOMPARE( m1.multInt( 2 , 1 ) ,  2 );
}

void TestQString::initTestCase( void )
{
  qDebug() << "first call";
}

void TestQString::cleanupTestCase( void )
{
  qDebug() << "last call";
}

void TestQString::toUpper( void )
{
  QFETCH( QString , string );
  QFETCH( QString , result );
  QCOMPARE( string.toUpper() , result );
}

void TestQString::toUpperMore( void )
{
  QString str = "Hello";
  QVERIFY( str.toUpper() == "HELLO" );
}

void TestQString::toUpper_data( void )
{
  QTest::addColumn<QString>("string");
  QTest::addColumn<QString>("result");
  QTest::newRow("allLower") << "hello" << "HELLO";
  QTest::newRow("mixed") << "Hello" << "HELLO";
  QTest::newRow("all upper") << "HELLO" << "HELLO";
}

void TestQString::firstBenchmark( void )
{
  QString str1, str2;
  QBENCHMARK {
    str1.localeAwareCompare(str2);
  }
}

QTEST_MAIN(TestQString)
#include "testqstring.moc"
