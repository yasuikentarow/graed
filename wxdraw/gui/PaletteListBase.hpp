﻿#pragma once

namespace wxdraw::gui {
/**
   編集可能リスト
*/
class PaletteListBase
  : public wxWindow
{
  using super = wxWindow;

 private:
  Palette* palette_;
  wxListView* list_;
  std::unique_ptr<wxImageList> imageList_;
  size_t index_;

 public:
  PaletteListBase(wxWindow* parent, Palette* palette);
  ~PaletteListBase() override = default;

  WXDRAW_GETTER(Palette, palette_);

  virtual void refresh() = 0;
  virtual void update() = 0;

  virtual void setGradient(const GradientPtr& gradient) {}

 protected:
  WXDRAW_GETTER(List, list_);
  WXDRAW_GETTER(ImageList, imageList_);

  MainFrame* getMainFrame() const;

  int appendImage(const wxBitmap& bitmap);
  const PaletteComponentPtr& getPaletteComponent() const;

  void selectItem(size_t index);
  void unselectItem();

  virtual PaletteItemPtr getItem(size_t index) const = 0;
  virtual void appendItem(size_t index) = 0;
  virtual void removeItem(size_t index) = 0;
  virtual void onSelectItem(const PaletteItemPtr& item);

 private:
  void onListItemSelected(wxListEvent& event);
  void onSize(wxSizeEvent& event);
  void onTool(wxCommandEvent& event);
};
}
