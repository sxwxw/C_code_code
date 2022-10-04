import 'package:flutter/material.dart';

void main() {
  runApp(myApp());
}

class myApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: Text('列表')),
        body: HomeContent(),
      ),
    );
  }
}

class HomeContent extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return stacks();
  }
}

// stack层叠组件 position
class stacks extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Center(
      child: Container(
        height: 200,
        width: 200,
        color: Colors.pink,
        child: Stack(
          children: const <Widget>[
            Positioned(
              left: 100,
              top: 100,
              child: Icon(Icons.ice_skating),
            ),
            Positioned(
              right: 100,
              child: Icon(Icons.icecream),
            ),
            Align(
              alignment: Alignment.bottomLeft,
              child: Icon(Icons.image_not_supported_outlined),
            ),
            Align(
              alignment: Alignment.bottomRight,
              child: Icon(Icons.image_sharp),
            ),
          ],
        ),
      ),
    );
  }
}
