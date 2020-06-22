/* eslint-disable prettier/prettier */
import React, {useEffect, useState} from 'react';
import Orientation from 'react-native-orientation';
import TcpSocket from 'react-native-tcp-socket';
import {Text} from 'react-native';

import {
  Container,
  ModalSettings,
  ModalContainer,
  ButtonsModalRow,
  ModalButton,
  ButtonsModalRowQuit,
  ModalButtonText,
} from './Style';

import Header from './Header';
import Menu from './Menu';
import Game from './Game';

const App = () => {
  const options = {
    port: 3034, //port 
    host: '192.168.1.18' // adress ip v4
  };
  const client = TcpSocket.createConnection(options);
  const [timer, setTimer] = useState();
  const [isModal, setModal] = useState(false);
  const [isRight, setSens] = useState(true);
  const [isButtonRight, setButtonSens] = useState(true);
  const [isButtonPlace, setButtonPlace] = useState(true);
  const [isConnect, setConnection] = useState(false);
  const [isConnectModal, setConnectionModal] = useState(false);
  useEffect(() => {
    Orientation.lockToLandscape();
  }, []);

  const onPressOut = () => {
    clearInterval(timer);
  };
  const handleOnDirUp = () => {
    client.write('13');
    console.log('up');
  };
  const handleOnDirUpLong = () => {
    // time a mettre en ms
    setTimer(setInterval(() => handleOnDirUp(), 100));
  };
  const handleOnDirDown = () => {
    client.write('15');
    console.log('down');
  };
  const handleOnDirDownLong = () => {
    // time a mettre en ms
    setTimer(setInterval(() => handleOnDirDown(), 100));
  };
  const handleOnDirLeft = () => {
    client.write('12');
    console.log('left');
  };
  const handleOnDirLeftLong = () => {
    // time a mettre en ms
    setTimer(setInterval(() => handleOnDirLeft(), 100));
  };
  const handleOnDirRight = () => {
    client.write('14');
    console.log('right');
  };
  const handleOnDirRightLong = () => {
    // time a mettre en ms
    setTimer(setInterval(() => handleOnDirRight(), 100));
  };
  const pressB = () => {
    client.write('0');
    console.log('B');
  };
  const pressA = () => {
    client.write('7');
    console.log('A');
  };
  const pressSelect = () => {
    client.write('1');
    console.log('Select');
  };
  const pressStart = () => {
    client.write('2');
    console.log('Start');
  };

  return (
    <Container>
      <Header setModal={setModal} isConnect={isConnect} setConnectionModal={setConnectionModal} setConnection={setConnection} />

      <Menu selectFct={pressSelect} startFct={pressStart} />

      <Game
        onPressOut={onPressOut}
        handleOnDirUp={handleOnDirUp}
        handleOnDirDown={handleOnDirDown}
        handleOnDirLeft={handleOnDirLeft}
        handleOnDirRight={handleOnDirRight}
        handleOnDirUpLong={handleOnDirUpLong}
        handleOnDirDownLong={handleOnDirDownLong}
        handleOnDirLeftLong={handleOnDirLeftLong}
        handleOnDirRightLong={handleOnDirRightLong}
        pressA={pressA}
        pressB={pressB}
        isRight={isRight}
        isButtonRight={isButtonRight}
        isButtonPlace={isButtonPlace}
      />

      <ModalSettings
        isVisible={isModal}
        onBackdropPress={() => setModal(false)}
        onBackButtonPress={() => setModal(false)}
      >
        <ModalContainer>
          <ButtonsModalRow>
            <ModalButton isButtonRight={!isRight} onPress={() => setSens(!isRight)}>
              <ModalButtonText>INVERSER COMMANDES</ModalButtonText>
            </ModalButton>
            <ModalButton isButtonRight={!isButtonRight} onPress={() => setButtonSens(!isButtonRight)}>
              <ModalButtonText>CHANGER A ET B</ModalButtonText>
            </ModalButton>
          </ButtonsModalRow>
          <ButtonsModalRow>
            <ModalButton isButtonRight={false}>
              <ModalButtonText>CHANGER PAD</ModalButtonText>
            </ModalButton>
            <ModalButton isButtonRight={!isButtonPlace} onPress={() => setButtonPlace(!isButtonPlace)}>
              <ModalButtonText>INVERSER A ET B</ModalButtonText>
            </ModalButton>
          </ButtonsModalRow>
          <ButtonsModalRowQuit>
            <ModalButton
              onPress={() => setModal(false)}
            >
              <ModalButtonText>QUITTER</ModalButtonText>
            </ModalButton>
          </ButtonsModalRowQuit>
        </ModalContainer>
      </ModalSettings>
    </Container>
  );
};

export default App;
