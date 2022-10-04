import 'package:flutter/material.dart';

void main() {
  runApp(myApp());
}

// 自定义组件 组件化开发 文本也当成一个组件
class myApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    // throw UnimplementedError();
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('sxwxw'),
        ),
        body: HomeContent(),
      ),
      theme: ThemeData(primarySwatch: Colors.yellow),
    );
  }
}

// 再次封装组件
class HomeContent extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    // throw UnimplementedError();
    // 第一种写法
    // return Center(
    //     child: Text('hnz',
    //         textDirection: TextDirection.ltr,
    //         style: TextStyle(fontSize: 40.0, color: Colors.blue)
    //         )
    //         );
    // 测试Container
    return Center(
      child: OneContainer(),
    );
  }
}

// container组件 类似Div
class OneContainer extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    // throw UnimplementedError();
    return Container(
        child: Text('hb',
            textAlign: TextAlign.center,
            style: TextStyle(
                color: Colors.red,
                fontSize: 40.0,
                backgroundColor: Colors.green)),
        width: 300.0,
        height: 300.0,
        decoration: BoxDecoration(
          color: Colors.yellow,
          border: Border.all(color: Colors.red, width: 2.0),
          borderRadius: BorderRadius.all(
            Radius.circular(10),
          ),
        ),
        // padding: EdgeInsets.all(20),
        // padding: EdgeInsets.fromLTRB(10, 20, 100, 50),
        // margin: EdgeInsets.all(20),
        // transform: Matrix4.translationValues(100, 0, 0),
        // transform: Matrix4.diagonal3Values(1.2, 1, 2),
        alignment: Alignment.bottomLeft);
  }
}
