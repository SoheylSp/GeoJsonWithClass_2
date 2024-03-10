#include <iostream>
#include <geojsonclass.h>
#include <QCoreApplication>

using namespace std ;



int main (int argc , char *argv[]){

    QCoreApplication app (argc , argv) ;

    if(argc < 7){

        cout << "Usage: ./tool --geojsonFile.geojson --tool <function> --feature <parameters>\n" ;
        return 1 ;

    }

    QString geojsonFile ;
    QString tool ;
    QString feature ;

    for (int i = 1 ; i< argc ; ++i){

        if(strcmp(argv[i],"--geojsonFile.geojson") == 0){
            geojsonFile = argv[i+1] ;
        }else if (strcmp(argv[i],"--tool")==0) {

            tool = argv[i+1] ;
        }else if(strcmp(argv[i],"--feature") == 0) {

            feature = argv[i+1] ;

        }

    }

    GeojsonClass geojson (geojsonFile) ;

    if(tool == "addLine"){

        //parse parameters for addLine function
        //Assuming format:addLine(lat1,lon1,lat2,lon2)

        int lat1,lon1,lat2,lon2 ;
        sscanf(feature.toStdString().c_str(),"addLine(%d,%d,%d,%d)",&lat1,&lon1,&lat2,&lon2) ;

        geojson.addLine(lat1,lon1,lat2,lon2) ;


    }else if (tool == "addCilrcle") {

        //parse parameters for addCrcle function
        //Assuming format:addCircle(centerLat,centerLon,radius)

        double centerLat , centerLon , radius ;
        sscanf(feature.toStdString().c_str() , "addCircle(%lf,%lf,%lf)",&centerLat,&centerLon,&radius) ;
        QGeoCoordinate center (centerLat,centerLon) ;
        geojson.addCircle(center,radius) ;

    } else if(tool == "calculateGreateCircle") {

        //parse parameters for calculateGraetCircle function
        //Assuming format : calculateGrateCircle(lat1,lon1,lat2,lon2)

        double lat1,lon1,lat2,lon2 ;
        int numPoints = 0 ;

        sscanf(feature.toStdString().c_str(),"calculateGreatCircle(%lf,%lf,%lf,%lf,%d)",&lat1,&lon1,&lat2,&lon2,numPoints) ;



        QGeoCoordinate point1 , point2 ;
        point1.setLatitude(lat1) ;
        point1.setLongitude(lon1);

        point2.setLatitude(lat2) ;
        point2.setLongitude(lon2);

        geojson.calculateGreatCircle(point1,point2,numPoints) ;
    }

    geojson.writeToFile();
    return 0 ;

}





/*

int main()
{
    GeojsonClass geoJson("lat_lon_ines.geojson");



    cout << "Select What You Want to do :\n " ;

    cout << "1- add Line \n" ;

    cout << "2- add Polygon \n" ;

    cout << "3-add Circle\n" ;

    cout << "4-calculate GreatCircle\n" ;

    int userPrompt  (0) ;

    cin >> userPrompt ;
    cin.get() ;

    if(userPrompt == 1){

        cout<<"Enter first point longitude : ";
        int firstPointLongitude ;
        cin >> firstPointLongitude ;
        cin.get();

        cout<<"Enter first point latitude : ";
        int firstPointLatitude ;
        cin >> firstPointLatitude ;
        cin.get();

        cout<<"Enter second poin longitude : ";
        int secondPointLongitude ;
        cin >> secondPointLongitude ;
        cin.get();

        cout<<"Enter second poin latitude : ";
        int secondPointLatitude ;
        cin >> secondPointLatitude ;
        cin.get();





        geoJson.addLine(firstPointLatitude,firstPointLongitude,secondPointLatitude,secondPointLongitude);



        geoJson.writeToFile();
        return 0 ;



    }else if (userPrompt == 2) {

        double p1Lt , p1Ln ,p2Lt , p2Ln ,p3Lt , p3Ln , p4Lt, p4Ln , p5Lt ,  p5Ln ;


        //Ponit 1

        cout << "Enter Point 1 Latitude as double: \n" ;

        cin >> p1Lt ;
        cin.get() ;


        cout << "Enter Point 1 longitude as double: \n" ;

        cin >> p1Ln ;
        cin.get() ;


        //Point 2


        cout << "Enter Point 2 Latitude as double: \n" ;

        cin >> p2Lt ;
        cin.get() ;


        cout << "Enter Point 2 longitude as double: \n" ;

        cin >> p2Ln ;
        cin.get() ;


        //Point 3


        cout << "Enter Point 3 Latitude as double: \n" ;

        cin >> p3Lt ;
        cin.get() ;


        cout << "Enter Point 3 longitude as double: \n" ;

        cin >> p3Ln ;
        cin.get() ;



        //Point 4


        cout << "Enter Point 4 Latitude as double: \n" ;

        cin >> p4Lt ;
        cin.get() ;


        cout << "Enter Point 4 longitude as double: \n" ;

        cin >> p4Ln ;
        cin.get() ;


        //Point 5


        cout << "Enter Point 5 Latitude as double: \n" ;

        cin >> p5Lt ;
        cin.get() ;


        cout << "Enter Point 5 longitude as double: \n" ;

        cin >> p5Ln ;
        cin.get() ;


          QGeoCoordinate c1 ;
          c1.setLatitude(p1Lt);
          c1.setLongitude(p1Ln);

          QGeoCoordinate c2 ;
          c2.setLatitude(p2Lt);
          c2.setLongitude(p2Ln);

          QGeoCoordinate c3 ;
          c3.setLatitude(p3Lt) ;
          c3.setLongitude(p3Ln);

          QGeoCoordinate c4 ;
          c4.setLatitude(p4Lt);
          c4.setLongitude(p4Ln);

          QGeoCoordinate c5 ;
          c5.setLatitude(p5Lt);
          c5.setLongitude(p5Ln);


          geoJson.addPolygon(c1,c2,c3,c4,c5);


          geoJson.writeToFile();
          return 0 ;


}else if (userPrompt == 3) {

        cout<<"Enter the center's coordinate and the Radius of the cricle:\n";

        double centerLt ;
        double centerLn ;
        double radius ;

        cin >> centerLt >> centerLn ;
        cin.get() ;

        cout << "Eneter the radius : \n" ;

        cin >> radius ;
        cin.get() ;


        QGeoCoordinate center ;
        center.setLatitude(centerLt);
        center.setLongitude(centerLn) ;

           geoJson.addCircle(center,radius) ;


           geoJson.writeToFile();
           return 0 ;

}else if (userPrompt == 4) {


        double p1Lt , p1Ln , p2Lt , p2Ln ;
        int interMediatePoints ;

        // getting first Point latitude and Longitude

        cout << "Enter the Point 1 latitude : \n  " ;

        cin >> p1Lt ;
        cin.get() ;

        cout << "Enter the Point 1 longitude : \n  " ;

        cin >> p1Ln ;
        cin.get() ;

        //getting second point latitude

        cout << "Enter  Point2 latitude : \n" ;

        cin >> p2Lt ;
        cin.get() ;

        cout << "Enter point2 Longitude:\n";
        cin >>p2Ln ;

        cout << "Eneter the Count of Enter Mediate Points:\n" ;

        cin >> interMediatePoints ;
        cin.get() ;

        QGeoCoordinate c1 , c2 ;
        c1.setLongitude(p1Lt) ;
        c1.setLatitude(p1Ln) ;

        c2.setLongitude(p2Lt) ;
        c2.setLatitude(p2Ln) ;

        geoJson.calculateGreatCircle(c1,c2,interMediatePoints) ;




        geoJson.writeToFile();
        return 0 ;





}









}
*/
