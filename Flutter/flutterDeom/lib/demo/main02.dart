import 'package:flutter/material.dart';

void main() {
  runApp(myApp());
}

// 图片组件
class myApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('sxwxw'),
        ),
        body: HomeContent(),
      ),
    );
  }
}

class HomeContent extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Center(
      child: FourImages(),
    );
  }
}

// 加载远程图片
class wangImage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Container(
      child: Image.network(
        "https://infinityicon.infinitynewtab.com/user-share-icon/d8b62f4d64bda8800b1c788cd5ba3c68.png?imageMogr2/thumbnail/240x/format/webp/blur/1x0/quality/100|imageslim",
        alignment: Alignment.topLeft,
        fit: BoxFit.cover,
      ),
      width: 400.0,
      height: 400.0,
      decoration: BoxDecoration(color: Colors.yellow),
    );
  }
}

// 圆角图片
class YuanImage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Container(
      width: 400.0,
      height: 400.0,
      decoration: BoxDecoration(
        color: Colors.yellow,
        // borderRadius: BorderRadius.all(Radius.circular(200))));
        borderRadius: BorderRadius.circular(200),
        image: DecorationImage(
            image: NetworkImage(
                "https://infinityicon.infinitynewtab.com/user-share-icon/d8b62f4d64bda8800b1c788cd5ba3c68.png?imageMogr2/thumbnail/240x/format/webp/blur/1x0/quality/100|imageslim"),
            fit: BoxFit.cover),
      ),
    );
  }
}

// clipoval
class ThreeImage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Container(
      child: ClipOval(
        child: Image.network(
          "https://infinityicon.infinitynewtab.com/user-share-icon/d8b62f4d64bda8800b1c788cd5ba3c68.png?imageMogr2/thumbnail/240x/format/webp/blur/1x0/quality/100|imageslim",
          width: 100,
          height: 100,
          fit: BoxFit.cover,
        ),
      ),
    );
  }
}

// 本地图片
class FourImages extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Container(
      child: Image.asset(
        'images/2.jpg',
        width: 100,
        height: 100,
        fit: BoxFit.cover,
      ),
    );
  }
}
