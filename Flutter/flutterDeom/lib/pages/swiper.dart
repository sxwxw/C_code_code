import 'package:flutter/material.dart';
import 'package:flutter_swiper/flutter_swiper.dart';

class swiper extends StatefulWidget {
  const swiper({Key? key}) : super(key: key);

  @override
  _swiperState createState() => _swiperState();
}

// class _swiperState extends State<swiper> {
//   List<Map> imgList = [
//     {'url': 'images/2.jpg'},
//     {'url': 'images/2.jpg'},
//     {'url': 'images/2.jpg'},
//     {'url': 'images/2.jpg'},
//   ];
//   @override
//   Widget build(BuildContext context) {
//     return Scaffold(
//       appBar: AppBar(
//         title: Text('轮播图'),
//       ),
//       body: Swiper(
//         itemBuilder: (BuildContext context, int index) {
//           return Image.asset(
//             imgList[index]['url'],
//             fit: BoxFit.fill,
//           );
//         },
//         itemCount: imgList.length,
//         // pagination: SwiperPagination(),
//         // control: SwiperControl(),
//       ),
//     );
//   }
// }
class _swiperState extends State<swiper> {
  List<Map> imgList = [
    {'url': 'images/2.jpg'},
    {'url': 'images/2.jpg'},
    {'url': 'images/2.jpg'},
    {'url': 'images/2.jpg'},
  ];
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('轮播图'),
      ),
      body: Column(
        children: [
          SizedBox(
            height: 200,
            child: AspectRatio(
              aspectRatio: 16 / 9,
              child: Swiper(
                itemBuilder: (BuildContext context, int index) {
                  return Image.asset(
                    imgList[index]['url'],
                    fit: BoxFit.fill,
                  );
                },
                itemCount: imgList.length,
              ),
            ),
          ),
        ],
      ),
    );
  }
}
