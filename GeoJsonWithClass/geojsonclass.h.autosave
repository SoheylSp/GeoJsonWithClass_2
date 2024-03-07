#ifndef GEOJSONCLASS_H
#define GEOJSONCLASS_H

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <QGeoCoordinate>
#include <QtMath>


class GeojsonClass
{
public:
    GeojsonClass(const QString& filename);

    void addLine(int lat1 , int lon1 , int lat2 , int lon2);
    void addX1(int lat1 , int lon1 );
    void addX2(int lat1 , int lon1 );

    
    void addPolygon(QGeoCoordinate point1, QGeoCoordinate point2  , QGeoCoordinate point3 , QGeoCoordinate point4 , QGeoCoordinate point5);

    void addCircle (const QGeoCoordinate &center , double radius) ;


    void calculateGreatCircle(const QGeoCoordinate& point1 , const QGeoCoordinate& point2 , int numPoints);

    void writeToFile ();


private:

    QString filename_   ;
    QJsonObject geojson_;
    QJsonArray features_;





};

#endif // GEOJSONCLASS_H
