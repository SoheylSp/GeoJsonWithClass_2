#include <iostream>
#include <geojsonclass.h>

using namespace std ;

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



        /* for (int lat = -360 ; lat <= 360 ; lat +=2 ){
            for (int lon = -180 ; lon <= 180 ; lon++){

                geoJson.addLine(-lat,lon,lat,lon);
                geoJson.addLine(lat,lon,lat,-lon);
                geoJson.addX1(lat,lon);
                geoJson.addX2(lat,lon);



            }
        }
        */

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
