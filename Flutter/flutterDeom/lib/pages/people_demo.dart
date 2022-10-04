import 'package:flutter/material.dart';

class people extends StatefulWidget {
  const people({Key? key}) : super(key: key);

  @override
  _peopleState createState() => _peopleState();
}

class _peopleState extends State<people> {
  late String username;
  int sex = 1;

  void _sexChanged(value) {
    setState(() {
      sex = value as int;
    });
  }

  List hobby = [
    {'check': true, 'title': '篮球'},
    {'check': false, 'title': '羽毛球'},
    {'check': false, 'title': '乒乓球'},
    {'check': false, 'title': '排球'}
  ];

  List<Widget> _getHobby() {
    List<Widget> tempList = [];
    for (var i = 0; i < hobby.length; i++) {
      tempList.add(
        Row(
          children: [
            Text(hobby[i]['title']),
            Checkbox(
              value: hobby[i]['check'],
              onChanged: (value) {
                setState(
                  () {
                    hobby[i]['check'] = value;
                  },
                );
              },
            ),
          ],
        ),
      );
    }
    return tempList;
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('爱好信息'),
      ),
      body: Padding(
        padding: EdgeInsets.all(20),
        child: Column(
          children: <Widget>[
            TextField(
              decoration: InputDecoration(
                hintText: '输入用户信息',
              ),
              onChanged: (value) {
                username = value;
              },
            ),
            Row(
              children: [
                Text('男'),
                Radio(
                  value: 1,
                  groupValue: sex,
                  onChanged: _sexChanged,
                ),
                Text('女'),
                Radio(
                  value: 2,
                  groupValue: sex,
                  onChanged: _sexChanged,
                ),
              ],
            ),
            Wrap(
              children: _getHobby(),
            )
          ],
        ),
      ),
    );
  }
}

class widget {}
