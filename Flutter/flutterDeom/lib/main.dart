import 'package:flutter/material.dart';
import 'routers/routes.dart';

void main() {
  runApp(myApp());
}

class myApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // ignore: todo
    // TODO: implement build
    return MaterialApp(
      initialRoute: '/dialog',
      onGenerateRoute: onGenerateRoute,
    );
  }
}
