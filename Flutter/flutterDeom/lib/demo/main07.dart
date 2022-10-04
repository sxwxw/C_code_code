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
    return demo();
  }
}

class butns extends StatelessWidget {
  final String text;

  const butns(this.text, {Key? key}) : super(key: key);
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return ElevatedButton(
      child: Text(text),
      onPressed: () {
        print('hhhh');
      },
    );
  }
}

class demo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Wrap(
      spacing: 10,
      runSpacing: 15,
      children: const <Widget>[
        butns('1'),
        butns('2'),
        butns('3'),
        butns('4'),
        butns('5'),
        butns('1'),
        butns('2'),
        butns('3'),
        butns('4'),
        butns('5'),
        butns('1'),
        butns('2'),
        butns('3'),
        butns('4'),
        butns('5'),
        butns('1'),
        butns('2'),
        butns('3'),
        butns('4'),
        butns('5'),
      ],
    );
  }
}
