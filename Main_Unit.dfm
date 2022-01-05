object Main_Form: TMain_Form
  Left = 188
  Top = 114
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'ZM Process Killer v0.23.11.2008'
  ClientHeight = 83
  ClientWidth = 345
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 149
    Height = 13
    Caption = 'Nom du processus '#224' terminer  : '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 40
    Width = 161
    Height = 13
    Caption = '(casse respect'#233'e, extancien inclu)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Terminate_SpeedButton: TSpeedButton
    Left = 208
    Top = 48
    Width = 129
    Height = 25
    Caption = '&Terminer Processus'
    Flat = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    OnClick = Terminate_SpeedButtonClick
  end
  object About_Label: TLabel
    Left = 16
    Top = 64
    Width = 42
    Height = 13
    Cursor = crHandPoint
    Caption = 'A propos'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
    OnClick = About_LabelClick
  end
  object Process_Edit: TEdit
    Left = 168
    Top = 16
    Width = 169
    Height = 21
    TabOrder = 0
  end
end
