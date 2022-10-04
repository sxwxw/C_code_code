import 'package:flutter/material.dart';

class shop extends StatefulWidget {
  Map arguments;
  shop({Key? key, required this.arguments}) : super(key: key);

  @override
  // ignore: no_logic_in_create_state
  _shopState createState() => _shopState(arguments: arguments);
}

class _shopState extends State<shop> {
  Map arguments;
  _shopState({required this.arguments});
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('商品页面'),
      ),
      body: Text('pid:${arguments['pid']}'),
    );
  }
}
