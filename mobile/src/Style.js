import styled from 'styled-components';
import Modal from 'react-native-modal';
import Icon from 'react-native-vector-icons/SimpleLineIcons';

export const Container = styled.View`
  flex: 1;
  background-color: #c4c4c4;
`;

export const SettingButton = styled.TouchableOpacity``;

export const SettingIcon = styled(Icon)`
  margin-right: 10px;
`;

export const ScoreText = styled.Text`
  font-size: 30px;
  color: #FFFFFF;
  margin-left: 10px;
`;

export const HeaderContainer = styled.View`
  flex: 0.15;
  background-color: #000000;
  flex-direction: row;
  justify-content: space-between;
  align-items: center;
`;

export const MenuContainer = styled.View`
  flex: 0.2;
  align-items: center;
  justify-content: center;
  flex-direction: row;
`;

export const SelectButton = styled.TouchableOpacity`
  width: 75px;
  height: 30%;
  border-width: 1px;
  margin-right: 20px;
  align-items: center;
  justify-content: center;
`;

export const GameContainer = styled.View`
  flex: 0.65;
  flex-direction: row;
`;

export const GameHalfContainer = styled.View`
  flex: 0.5;
`;

export const GamePadContainer = styled.View`
  flex: 1;
`;

export const GamePadPlusBorder = styled.View`
  flex: 0.5;
  justify-content: center;
  align-items: center;
`;

export const GamePadPlusMiddle = styled.View`
  flex: 0.5;
  flex-direction: row;
  align-items: center;
  justify-content: center;
`;

export const EmptyGameButton = styled.View`
  width: 75px;
  height: 100%;
`;

export const GamePadButton = styled.TouchableOpacity`
  width: 75px;
  height: 100%;
  justify-content: center;
  align-items: center;
  border-radius: 20px;
`;

export const ButtonsRow = styled.View`
  flex: 0.5;
  flex-direction: row;
`;

export const ButtonContainer = styled.View`
  flex: 0.5;
  justify-content: center;
  align-items: center;
`;

export const GameButtonView = styled.TouchableOpacity`
  width: 75px;
  height: 75px;
  border-width: 1px;
  border-radius: 100px;
  justify-content: center;
  align-items: center;
`;

export const ModalButton = styled.TouchableOpacity`
  width: 200px;
  height: 90%;
  border-width: 1px;
  border-radius: 25px;
  justify-content: center;
  align-items: center;
  background-color: ${props => (props.isButtonRight ? 'green' : 'transparent')};
`;

export const ModalButtonText = styled.Text`
  font-size: 17px;
`;

export const ButtonsModalRow = styled.View`
  flex: 0.5;
  flex-direction: row;
  align-items: center;
  margin-horizontal: 10%;
  justify-content: space-between;
`;

export const ButtonsModalRowQuit = styled.View`
  flex: 0.5;
  flex-direction: row;
  align-items: center;
  justify-content: center;
`;

export const ModalSettings = styled(Modal)`
  flex: 0.7;
`;

export const ModalContainer = styled.View`
  flex: 1;
  background-color: #FFFFFF;
  border-radius: 25px;
`;

export const ConnectionContainer = styled.TouchableOpacity`
  height: 100%;
  width: 30%;
  align-items: center;
  justify-content: center;
  flex-direction: row;
`;

export const ButtonConnect = styled.View`
  height: 30px;
  width: 30px;
  margin-top: 5px;
  margin-left: 10px;
  border-radius: 100px;
  border-width: 2px;
  background-color: ${props => props.isConnect ? 'green' : 'red'};
`;
