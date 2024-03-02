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
