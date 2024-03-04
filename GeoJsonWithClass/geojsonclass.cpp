#include "geojsonclass.h"

GeojsonClass::GeojsonClass(const QString& filename):filename_(filename)
{

    geojson_["type"] = "FeatureCollection" ;
    geojson_["name"] = "geo" ;


}

void GeojsonClass::addLine(int lat1, int lon1, int lat2, int lon2)
{
    QJsonObject feature;
    QJsonObject properties ;
    QJsonObject geometry ;
    QJsonArray coordinates ;

    feature["type"]="Feature";
    feature["properties"] = properties ;
    geometry["type"] = "LineString" ;
    coordinates.append(QJsonArray({lat1,lon1}));
    coordinates.append(QJsonArray({lat2,lon2}));

    geometry["coordinates"] = coordinates ;
    feature["geometry"] = geometry ;

    features_.append(feature) ;





}

void GeojsonClass::addX1(int lat1, int lon1)
{



    QJsonObject feature ;
    QJsonObject properties ;
    QJsonObject geometry ;
    QJsonArray coordinates ;

    feature["type"] = "Feature" ;
    feature["properties"]=properties ;
    geometry["type"] = "LineString" ;
    coordinates.append(QJsonArray({lat1,lon1}));
    coordinates.append(QJsonArray({lat1 - 2 , lon1-1})) ;
    geometry["coordinates"]=coordinates;
    feature["geometry"]=geometry;
    features_.append(feature) ;

}

void GeojsonClass::addX2(int lat1, int lon1)
{
    QJsonObject feature ;
    QJsonObject properties ;
    QJsonObject geometry ;
    QJsonArray coordinates ;

    feature["type"] = "Feature" ;
    feature["properties"]=properties ;
    geometry["type"] = "LineString" ;
    coordinates.append(QJsonArray({-lat1,lon1}));
    coordinates.append(QJsonArray({-lat1 + 2 , lon1-1})) ;
    geometry["coordinates"]=coordinates;
    feature["geometry"]=geometry;
    features_.append(feature) ;
}

void GeojsonClass::addPolygon(QGeoCoordinate coordinate1, QGeoCoordinate coordinate2, QGeoCoordinate coordinate3, QGeoCoordinate coordinate4 , QGeoCoordinate coordinate5)
{
    QJsonObject feature ;
    QJsonObject properties ;
    QJsonObject geometry ;
    QJsonArray coordinates ;

    feature["type"]="Feature";
    feature["properties"]=properties;
    geometry["type"] = "Polygon";
    coordinates.append(QJsonArray({coordinate1.longitude(),coordinate1.latitude()}));
    coordinates.append(QJsonArray({coordinate2.longitude(),coordinate2.latitude()}));
    coordinates.append(QJsonArray({coordinate3.longitude(),coordinate3.latitude()}));
    coordinates.append(QJsonArray({coordinate4.longitude(),coordinate4.latitude()}));
    coordinates.append(QJsonArray({coordinate5.longitude(),coordinate5.latitude()}));

    geometry["coordinates"] = coordinates ;
    feature["geometry"] =geometry ;
    features_.append(feature) ;


}




void GeojsonClass::writeToFile()
{
    QFile geoJsonFile(filename_);
    if(!geoJsonFile.open(QIODevice::WriteOnly|QIODevice::Text)){

        qWarning()<<"Faild to open file for writing";
        return ;




    }
    geojson_["features"]= features_;
    QJsonDocument jsonDoc(geojson_);
    geoJsonFile.write(jsonDoc.toJson());
    geoJsonFile.close();

    qDebug()<<"GeoJson file create suuccessfully : " << filename_ ;
}
