CREATE INDEX supplier_id_index
ON supplier (supplier_id);

CREATE INDEX part_nyc_index
ON part_nyc (part_number);

CREATE INDEX part_sfo_index
ON part_sfo (part_number);

CREATE INDEX part_nyc_supplier
ON part_nyc (supplier);

CREATE INDEX part_sfo_supplier
ON part_sfo (supplier);

CREATE INDEX part_nyc_on_hand
ON part_nyc (on_hand);

CREATE INDEX part_sfo_on_hand
ON part_sfo (on_hand);

CREATE INDEX part_nyc_color
ON part_nyc (color);

CREATE INDEX part_sfo_color
ON part_sfo (color);
