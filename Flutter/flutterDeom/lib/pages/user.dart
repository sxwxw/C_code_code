import 'package:flutter/material.dart';

class UserInfo extends StatelessWidget {
  const UserInfo({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('用户中心'),
      ),
      body: Column(
        children: const <Widget>[
          Padding(
            padding: EdgeInsets.all(20),
            child: Center(
              child: CircleAvatar(
                backgroundImage: AssetImage('images/2.jpg'),
              ),
            ),
          ),
          Text(
            'wxw',
            style: TextStyle(fontSize: 20),
          ),
          Text('hbycsxdx')
        ],
      ),
    );
  }
}
