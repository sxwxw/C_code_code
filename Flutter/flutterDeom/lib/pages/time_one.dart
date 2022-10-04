import 'package:flutter/material.dart';
import 'package:date_format/date_format.dart';
import 'package:flutter_datetime_picker/flutter_datetime_picker.dart';

class times extends StatefulWidget {
  const times({Key? key}) : super(key: key);

  @override
  _timesState createState() => _timesState();
}

class _timesState extends State<times> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('时间戳'),
      ),
      body: oneTime(),
    );
  }
}

class oneTime extends StatefulWidget {
  const oneTime({Key? key}) : super(key: key);

  @override
  _oneTimeState createState() => _oneTimeState();
}

class _oneTimeState extends State<oneTime> {
  var now = DateTime.now();
  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    // print(now);  2021-10-20 13:29:20.883699
    // print(now.microsecondsSinceEpoch); 1634707797087514 时间戳
    // print(DateTime.fromMillisecondsSinceEpoch(1634707797087514));
    print(formatDate(DateTime.now(), [yyyy, '年', mm, '月', dd]));
  }

  @override
  Widget build(BuildContext context) {
    return Container();
  }
}
